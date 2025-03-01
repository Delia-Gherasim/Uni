package com.example.moviemanager

import java.io.Serializable

data class MovieData (
    var id: Int,
    var name: String,
    var genre: String,
    var status: Boolean,
    var director: String? = null,
    var description: String? = null,
    var rating: Float? = null
):Serializable{
    fun checkRating(rating: Float): Boolean {
        return rating > 0 && rating <= 5
    }
    fun validateName(name: String): Boolean {
        return name.length < 50 && name!="mandatory" && name.length>0
    }
    fun validateGenre(genre: String): Boolean {
        val genres = listOf("Action","Comedy","Drama","Horror","Science Fiction","Romance","Thriller")
        return genre in genres
    }
    fun validateDirector(director: String): Boolean {
        return director.length < 30 && director != "optional"
    }
    fun validateDescription(description: String): Boolean {
        return description.length < 356 && description != "optional"
    }
}