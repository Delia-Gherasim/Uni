package com.example.moviemanager

import android.app.AlertDialog
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.CheckBox
import android.widget.EditText
import android.widget.RatingBar
import android.widget.Spinner
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import com.google.android.material.floatingactionbutton.FloatingActionButton

class EditActivity : AppCompatActivity() {
    private var movieId: Int = -1

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_edit)

        movieId = intent.getIntExtra("movieId", -1)

        if (movieId == -1) {
            Log.e("EditActivity", "Invalid movie ID")
            finish()
            return
        }

        val repository = Repo.getInstance(this)
        val movie = repository.getMovieById(movieId)

        val genreSpinner: Spinner = findViewById(R.id.genreDropDown2)
        val genres = resources.getStringArray(R.array.genres_array)
        val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, genres)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        genreSpinner.adapter = adapter

        val nameInput: EditText = findViewById(R.id.editName)
        nameInput.setText(movie.name)
        val directorInput: EditText = findViewById(R.id.editDirector)
        directorInput.setText(movie.director)
        val descriptionInput: EditText = findViewById(R.id.editDescription)
        descriptionInput.setText(movie.description)
        val statusCheckBox: CheckBox = findViewById(R.id.checkBox2)
        statusCheckBox.isChecked = movie.status

        val ratingBar: RatingBar = findViewById(R.id.ratingBar3)
        if (movie.status)
            ratingBar.rating = movie.rating ?: 0f
        else
            ratingBar.rating = 0f

        statusCheckBox.setOnCheckedChangeListener { _, isChecked ->
            ratingBar.visibility = if (isChecked) View.VISIBLE else View.GONE
        }

        val backBtn: FloatingActionButton = findViewById(R.id.goBackBtn)
        backBtn.setOnClickListener {
            finish()
        }
        val saveButton: Button = findViewById(R.id.saveButton2)
        saveButton.setOnClickListener {
            try {
                val name = nameInput.text.toString()
                val genre = genreSpinner.selectedItem.toString()
                val status = statusCheckBox.isChecked
                val rating = if (status) ratingBar.rating else null
                val description = if (descriptionInput.text.toString() == "optional") null else descriptionInput.text.toString()
                val director = if (directorInput.text.toString() == "optional") null else directorInput.text.toString()

                val newMovie = MovieData(movieId, name, genre, status, director, description, rating)

                if(repository.validateMovie(newMovie)) {
                    repository.updateMovie(movieId, newMovie)
                    Log.d("EditActivity", "Movie edited: $newMovie")

                }

                    finish()
            } catch (e: Exception) {
                Log.e("EditActivity", "Failed to edit movie", e)
                AlertDialog.Builder(this).apply {
                    setTitle("Edit failed")
                    setMessage("Error"+e.message)

                    setNegativeButton("Cancel") { dialog, _ ->
                        dialog.dismiss()
                    }

                    create()
                    show()
                }
            }
        }
    }
}
