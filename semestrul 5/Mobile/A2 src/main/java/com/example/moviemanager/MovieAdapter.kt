package com.example.moviemanager

import android.app.AlertDialog
import android.content.Context
import android.content.Intent
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.RatingBar
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.floatingactionbutton.FloatingActionButton

class MovieAdapter(
    var movies: List<MovieData>
) : RecyclerView.Adapter<MovieAdapter.MovieViewHolder>() {

    inner class MovieViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val editButton: FloatingActionButton = itemView.findViewById(R.id.editButton)
        val deleteButton: FloatingActionButton = itemView.findViewById(R.id.deleteButton)
        val movieTitle: TextView = itemView.findViewById(R.id.tvTitle)
        val director: TextView? = itemView.findViewById(R.id.tvDirector)
        val genre: TextView = itemView.findViewById(R.id.tvGenre)
        val description: TextView? = itemView.findViewById(R.id.tvDescription)
        val rating: RatingBar? = itemView.findViewById(R.id.ratingBar)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MovieViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.movie_layout, parent, false)
        return MovieViewHolder(view)
    }

    override fun onBindViewHolder(holder: MovieViewHolder, position: Int) {
        val movie = movies[position]

        holder.movieTitle.text = movie.name
        holder.director?.text = movie.director ?: "Unknown Director"
        holder.genre.text = movie.genre
        holder.description?.text = movie.description ?: "No Description Available"

        if (movie.status) {
            holder.rating?.visibility = View.VISIBLE
            holder.rating?.rating = movie.rating ?: 0f
        } else {
            holder.rating?.visibility = View.GONE
        }

        holder.editButton.setOnClickListener {
            val context = holder.itemView.context
            val intent = Intent(context, EditActivity::class.java)
            intent.putExtra("movieId", movie.id)
            context.startActivity(intent)
        }

        holder.deleteButton.setOnClickListener {
            showDeleteConfirmationDialog(holder.itemView.context, movie.id)
        }
    }

    override fun getItemCount(): Int {
        return movies.size
    }

    fun updateMovies(newMovies: List<MovieData>) {
        movies = newMovies
        notifyDataSetChanged()
    }

    private fun showDeleteConfirmationDialog(context: Context, movieId: Int) {
        AlertDialog.Builder(context).apply {
            setTitle("Delete Confirmation")
            setMessage("Are you sure you want to delete this movie?")

            setPositiveButton("Delete") { dialog, _ ->
                val repository = Repo.getInstance(context)
                repository.deleteMovie(movieId)

                Log.d("Delete", "Movie with ID: $movieId deleted.")
                (context as? MainActivity)?.refreshMovieList()
                dialog.dismiss()
            }

            setNegativeButton("Cancel") { dialog, _ ->
                dialog.dismiss()
            }

            create()
            show()
        }
    }

}
