package com.example.moviemanager

import android.content.Intent
import android.os.Bundle
import android.widget.Switch
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.android.material.floatingactionbutton.FloatingActionButton
import java.io.Console

class MainActivity : AppCompatActivity() {
    private lateinit var recyclerView: RecyclerView
    private lateinit var adapter: MovieAdapter
    private lateinit var repo: Repo

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        recyclerView = findViewById(R.id.listView)

//        val movieList = mutableListOf(
//            MovieData(
//                0,
//                "The Dark Knight",
//                "Action",
//                false,
//                "Christopher Nolan",
//                "When the menace known as the Joker emerges from his mysterious past, he wreaks havoc and chaos on the people of Gotham.",
//                4.5f
//            ),
//            MovieData(1,
//                "The Matrix",
//                "Science Fiction",
//                false,
//                "Lana Wachowski, Lilly Wachowski",
//                "A computer hacker learns from mysterious rebels about the true nature of his reality and his role in the war against its controllers.",
//                4f
//            ),
//            MovieData(2,
//                "The Lord of the Rings: The Return of the King",
//                "Fantasy",
//                true,
//                "Peter Jackson",
//                "Gandalf and Aragorn lead the World of Men against Sauron's army to rescue the hobbits and save Middle-Earth.",
//                3.9f
//            ),
//            MovieData(3,
//                "Schindler's List",
//                "Biography",
//                false,
//                "Steven Spielberg",
//                "In German-occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution.",
//                3.9f
//            ),
//            MovieData(4,
//                "The Silence of the Lambs",
//                "Thriller",
//                false,
//                "Jonathan Demme",
//                "A young FBI cadet must confide in an incarcerated and manipulative killer to receive his help on catching another serial killer who skins his victims.",
//                3.7f
//            ),
//            MovieData(5,
//                "The Social Network",
//                "Biography",
//                false,
//                "David Fincher",
//                "As Harvard students create the social networking site that would become known as Facebook, they must deal with backlash from friends and foes alike.",
//                3.5f
//            ),
//            MovieData(6,
//                "Coco",
//                "Animation",
//                true,
//                "Lee Unkrich",
//                "Aspiring musician Miguel, confronted with his family's ancestral ban on music, enters the Land of the Dead to find his great-great-grandfather, a legendary singer.",
//                3.6f
//            ),
//            MovieData(7,
//                "Spider-Man: Into the Spider-Verse",
//                "Animation",
//                true,
//                "Bob Persichetti, Peter Ramsey, Rodney Rothman",
//                "Teen Miles Morales becomes the Spider-Man of his dimension, and must join forces with five other Spider-Men from various dimensions to stop a threat to all realities.",
//                4.2f
//            ),
//            MovieData(8,
//                "Zootopia",
//                "Animation",
//                true,
//                "Byron Howard, Rich Moore",
//                "In a city of anthropomorphic animals, a bunny cop and a cynical con artist fox must work together to uncover a conspiracy.",
//                4.0f
//            ),
//            MovieData(9,
//                "Toy Story",
//                "Animation",
//                true,
//                "John Lasseter",
//                "A cowboy doll is profoundly threatened and jealous when a new spaceman figure supplants him as top toy in a boy's room.",
//                4.1f
//            )
//        )
        repo = Repo.getInstance(this)
        adapter = MovieAdapter(repo.getNotSeenMovies())
        recyclerView.adapter = adapter
        recyclerView.layoutManager = LinearLayoutManager(this)

        val switch: Switch = findViewById(R.id.switch1)
        switch.setOnCheckedChangeListener { _, isChecked ->
            refreshMovieList()
        }
        val addButton: FloatingActionButton = findViewById(R.id.addButton)
        addButton.setOnClickListener {
            val intent = Intent(this, AddActivity::class.java)
            startActivity(intent)
        }

    }
    override fun onResume() {
        super.onResume()
        refreshMovieList()
    }

    fun refreshMovieList() {
        val showSeen:Boolean = findViewById<Switch>(R.id.switch1).isChecked
        val movies = if (showSeen) {
            Repo.getInstance(this).getSeenMovies()
        } else {
            Repo.getInstance(this).getNotSeenMovies()
        }
        adapter.updateMovies(movies)
    }
}
