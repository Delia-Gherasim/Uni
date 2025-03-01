package com.example.moviemanager

import android.content.Context
import com.example.moviemanager.Repository.SQLite

class Repo private constructor(private val context: Context) {
    private val movieList: MutableList<MovieData> = mutableListOf()

    init {
        loadFromDbToMemory()
    }

    fun getAllMovies() = movieList
    fun getSeenMovies() = movieList.filter { it.status }
    fun getNotSeenMovies() = movieList.filter { !it.status }

    private fun loadFromDbToMemory() {
        val sqlite = SQLite.instanceOfDatabase(context)
        movieList.clear()
        movieList.addAll(sqlite.getAllMovies())
    }

    fun getMovieById(id: Int): MovieData {
        return movieList.first { it.id == id }
    }

    fun addMovie(movie: MovieData) {
        val sqlite = SQLite.instanceOfDatabase(context)
        sqlite.addMovieToDatabase(movie)
        loadFromDbToMemory()
    }

    fun deleteMovie(id: Int): Boolean {
        val index = movieList.indexOfFirst { it.id == id }
        if (index == -1) throw Exception("Movie not found")
        val sqlite = SQLite.instanceOfDatabase(context)
        sqlite.deleteMovie(id)
        loadFromDbToMemory()
        return true
    }

    fun updateMovie(id: Int, movie: MovieData): Boolean {
        val index = movieList.indexOfFirst { it.id == id }
        if (index == -1) throw Exception("Movie not found")
        val sqlite = SQLite.instanceOfDatabase(context)
        sqlite.updateMovieInDb(movie)
        loadFromDbToMemory()
        return true
    }

    fun validateMovie(movie: MovieData): Boolean {
        if (!movie.validateName(movie.name)) throw Exception("Invalid movie name")
        if (!movie.validateGenre(movie.genre)) throw Exception("Invalid genre")
        movie.description?.let {
            if (!movie.validateDescription(it)) throw Exception("Invalid description")
        }
        movie.rating?.let {
            if (!movie.checkRating(it)) throw Exception("Invalid rating")
        }
        return true
    }

    companion object {
        @Volatile private var instance: Repo? = null

        fun getInstance(context: Context): Repo {
            return instance ?: synchronized(this) {
                instance ?: Repo(context).also { instance = it }
            }
        }
    }


}
