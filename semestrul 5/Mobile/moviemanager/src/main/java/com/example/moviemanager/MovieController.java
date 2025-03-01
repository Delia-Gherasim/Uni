package com.example.moviemanager;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.io.Console;
import java.util.List;

@CrossOrigin(origins = "*")
@RestController
@RequestMapping("/")
public class MovieController {

    @Autowired
    private MovieRepository movieRepository;


    @GetMapping
    public List<Movie> getAllMovies() {
        System.out.println("GET ALL MOVIES CALLED");
        return movieRepository.findAll();
    }
    @GetMapping("/filter")
    public List<Movie> getMoviesByStatus(@RequestParam(required = false) Boolean showSeen) {
        System.out.println("FILTERING CALLED");
        if (showSeen != null) {
            return movieRepository.findByStatus(showSeen);
        }
        return movieRepository.findAll();
    }

    @GetMapping("/{id}")
    public Movie getMovieById(@PathVariable int id) {
        System.out.println("GET MOVIE BY ID: ");
        System.out.print(id);
        System.out.println(movieRepository.findById(id).orElse(null));
        return movieRepository.findById(id).orElse(null);
    }

    @PostMapping
    public Movie createMovie(@RequestBody Movie movie) {
        System.out.println("ADD NEW MOVIE");
        System.out.println(movie.getId()+" "+movie.getName()+" "+movie.getDirector()+" "+movie.getDescription()+" "+movie.getGenre()+" "+movie.getRating());
        return movieRepository.save(movie);
    }

    @PutMapping("/{id}")
    public Movie updateMovie(@PathVariable int id, @RequestBody Movie movie) {
        System.out.println("UPDATE MOVIE");
        System.out.println(movie.getId()+" "+movie.getName()+" "+movie.getDirector()+" "+movie.getDescription()+" "+movie.getGenre()+" "+movie.getRating());

        if (movieRepository.existsById(id)) {
            movie.setId(id);
            return movieRepository.save(movie);
        }
        return null;
    }

    @DeleteMapping("/{id}")
    public void deleteMovie(@PathVariable int id) {
        System.out.println("DELETE MOVIE "+ new String(String.valueOf(id)));
        movieRepository.deleteById(id);
    }

}