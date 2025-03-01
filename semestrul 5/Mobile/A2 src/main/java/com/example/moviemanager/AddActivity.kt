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
import androidx.appcompat.app.AppCompatActivity
import androidx.collection.emptyLongSet
import com.google.android.material.floatingactionbutton.FloatingActionButton

class AddActivity (): AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add)

        val genreSpinner: Spinner = findViewById(R.id.genreDropDown)
        val genres = resources.getStringArray(R.array.genres_array)
        val adapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, genres)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        genreSpinner.adapter = adapter

        val nameInput: EditText = findViewById(R.id.addName)
        val directorInput: EditText = findViewById(R.id.addDirector)
        val descriptionInput: EditText = findViewById(R.id.addDescription)
        val ratingBar: RatingBar = findViewById(R.id.ratingBar2)
        val statusCheckBox: CheckBox = findViewById(R.id.checkBox)

        val backBtn : FloatingActionButton = findViewById(R.id.goBackBtn)
        backBtn.setOnClickListener{
            finish()
        }

        val saveButton: Button = findViewById(R.id.saveButton)
        saveButton.setOnClickListener {
            try {
                val name = nameInput.text.toString()
                val genre = genreSpinner.selectedItem.toString()
                val status = statusCheckBox.isChecked
                val rating = if (status) ratingBar.rating else null
                val description = if (descriptionInput.text.toString() == "optional") null else descriptionInput.text.toString()
                val director = if (directorInput.text.toString() == "optional") null else directorInput.text.toString()

                statusCheckBox.setOnCheckedChangeListener { _, isChecked ->
                    ratingBar.visibility = if (isChecked) View.VISIBLE else View.GONE
                }

                val repository = Repo.getInstance(this)
                val newId= repository.getAllMovies().size+1
                val movie = MovieData(newId, name, genre, status, director, description, rating)
                if(repository.validateMovie(movie))
                {
                    repository.addMovie(movie)
                    Log.d("AddActivity", "Movie added: $movie")
                }
                else{
                    Log.d("AddActivity", "Invalid movie")
                    AlertDialog.Builder(this).apply {
                        setTitle("Add failed")
                        setMessage("Invalid data")

                        setNegativeButton("Cancel") { dialog, _ ->
                            dialog.dismiss()
                        }

                        create()
                        show()
                    }
                }

                finish()
            } catch (e: Exception) {
                Log.e("AddActivity", "Failed to add movie", e)
                AlertDialog.Builder(this).apply {
                    setTitle("Add failed")
                    setMessage("error: "+e.message)

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
