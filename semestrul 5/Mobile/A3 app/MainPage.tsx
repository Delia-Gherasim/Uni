import React, { useEffect, useState } from "react";
import { FlatList, Modal, StyleSheet, Switch, Text, TouchableOpacity, View } from "react-native";
import Add from "./Add";
import Edit from "./Edit";
import Movie from './Movie';
import Repository from "./Repository";

export default function MainPage() {
  const [checked, setChecked] = useState(false);
  const [listToBeShown, setListToBeShown] = useState<Movie[]>([]);
  const [showAddPage, setShowAddPage] = useState(false);
  const [showEditPage, setShowEditPage] = useState(false);
  const [selectedMovie, setSelectedMovie] = useState<Movie | null>(null);
  const [open, setOpen] = useState(false);

  const initialMovies = Repository();
  const [movies, setMovies] = useState<Movie[]>(initialMovies);

  const handleClickOpen = (movie: Movie) => {
    setSelectedMovie(movie);
    setOpen(true);
  };

  const handleClose = () => {
    setOpen(false);
  };

  const handleChange = (value: boolean) => {
    setChecked(value);
  };

  const renderList = (seen: boolean) => {
    setListToBeShown(movies.filter((movie) => movie.seen === seen));
  };

  const handleAddMovie = (newMovie: Movie) => {
    setMovies((prevMovies) => [...prevMovies, newMovie]);
    setShowAddPage(false);
  };

  const handleEditMovie = (updatedMovie: Movie) => {
    setMovies((prevMovies) =>
      prevMovies.map((movie) => (movie.id === updatedMovie.id ? updatedMovie : movie))
    );
    setShowEditPage(false);
  };

  const handleEditButtonClick = (movie: Movie) => {
    setSelectedMovie(movie);
    setShowEditPage(true);
  };

  const handleDeleteButtonClick = (movie: Movie) => {
    handleClickOpen(movie);
  };

  const handleDelete = () => {
    if (selectedMovie) {
      setMovies((prevMovies) =>
        prevMovies.filter((movie) => movie.id !== selectedMovie.id)
      );
      setListToBeShown((prevList) =>
        prevList.filter((movie) => movie.id !== selectedMovie.id)
      );
    }
    setOpen(false);
  };

  useEffect(() => {
    renderList(checked);
  }, [checked, movies]);

  if (showAddPage) {
    return <Add onAdd={handleAddMovie} onBack={() => setShowAddPage(false)} />;
  }

  if (showEditPage && selectedMovie) {
    return <Edit movie={selectedMovie} onEdit={handleEditMovie} onBack={() => setShowEditPage(false)} />;
  }

  return (
    <View style={styles.container}>
      <View style={styles.topBar}>
        <View style={styles.checkboxContainer}>
          <Switch value={checked} onValueChange={handleChange} />
          <Text style={styles.checkboxLabel}>Seen</Text>
        </View>
        <Text style={styles.title}>MyMovie</Text>
        <TouchableOpacity style={styles.addButton} onPress={() => setShowAddPage(true)}>
          <Text style={styles.addButtonText}>Add Movie</Text>
        </TouchableOpacity>
      </View>
      <FlatList
        data={listToBeShown}
        keyExtractor={(item) => item.id.toString()}
        renderItem={({ item }) => (
          <View style={styles.movieItem}>
            <Text style={styles.movieTitle}>{item.title}</Text>
            <Text style={styles.movieGenre}>{item.genre}</Text>
            <Text style={styles.movieDirector}>{item.director || "No director available"}</Text>
            <Text style={styles.movieDescription}>{item.description || "No description available"}</Text>
            {item.seen && <Text style={styles.movieRating}>Rating: {item.rating}/5</Text>}

            <View style={styles.buttonContainer}>
              <TouchableOpacity style={styles.editButton} onPress={() => handleEditButtonClick(item)}>
                <Text style={styles.buttonText}>Edit</Text>
              </TouchableOpacity>
              <TouchableOpacity style={styles.deleteButton} onPress={() => handleDeleteButtonClick(item)}>
                <Text style={styles.buttonText}>Delete</Text>
              </TouchableOpacity>
            </View>
          </View>
        )}
        contentContainerStyle={styles.flatListContainer}
      />

      <Modal visible={open} transparent={true} animationType="fade" onRequestClose={handleClose}>
        <View style={styles.dialogOverlay}>
          <View style={styles.dialogBox}>
            <Text style={styles.dialogTitle}>Are you sure you want to delete this movie?</Text>
            <View style={styles.dialogButtons}>
              <TouchableOpacity style={styles.dialogButton} onPress={handleClose}>
                <Text style={styles.dialogButtonText}>Cancel</Text>
              </TouchableOpacity>
              <TouchableOpacity style={styles.dialogButton} onPress={handleDelete}>
                <Text style={styles.dialogButtonText}>Confirm</Text>
              </TouchableOpacity>
            </View>
          </View>
        </View>
      </Modal>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 20,
    justifyContent: 'flex-start',
  },
  topBar: {
    position: "absolute",
    top: 0,
    left: 0,
    right: 0,
    padding: 10,
    backgroundColor: "#eaddff",
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    zIndex: 1000,
    width: "auto",
  },
  checkboxContainer: {
    flexDirection: "row",
    alignItems: "center",
  },
  checkboxLabel: {
    color: "black",
    marginLeft: 5,
  },
  flatListContainer: {
    paddingTop: 70, 
  },
  title: {
    fontSize: 18,
    color: "black",
    marginLeft: 10,
  },
  addButton: {
    padding: 10,
    backgroundColor: "#65558f",
    borderRadius: 5,
  },
  addButtonText: {
    color: "white",
    fontSize: 16,
  },
  movieItem: {
    backgroundColor: "#fef7ff",
    padding: 20,
    marginBottom: 15,
    borderRadius: 8,
    width: "100%",
    alignItems: "center",
    boxShadow:"5px 0px 7px 5px gray"
    
  },
  movieTitle: {
    fontSize: 18,
    fontWeight: "bold",
  },
  movieGenre: {
    fontSize: 16,
    marginTop: 5,
  },
  movieDirector: {
    fontSize: 14,
    marginTop: 5,
  },
  movieDescription: {
    fontSize: 14,
    marginTop: 5,
    textAlign: "center",
  },
  movieRating: {
    marginTop: 10,
    fontSize: 14,
    color: "#555",
  },
  buttonContainer: {
    flexDirection: "row",
    marginTop: 10,
  },
  editButton: {
    backgroundColor: "#65558f",
    padding: 10,
    borderRadius: 5,
    marginRight: 10,
  },
  deleteButton: {
    backgroundColor: "#65558f",
    padding: 10,
    borderRadius: 5,
  },
  buttonText: {
    color: "white",
    fontSize: 16,
  },
  dialogOverlay: {
    position: "absolute",
    top: 0,
    left: 0,
    right: 0,
    bottom: 0,
    backgroundColor: "rgba(0, 0, 0, 0.5)",
    justifyContent: "center",
    alignItems: "center",
  },
  dialogBox: {
    backgroundColor: "#fff",
    padding: 20,
    borderRadius: 5,
    width: "80%",
    alignItems: "center",
  },
  dialogTitle: {
    fontSize: 18,
    marginBottom: 20,
  },
  dialogButtons: {
    flexDirection: "row",
    justifyContent: "space-between",
  },
  dialogButton: {
    padding: 10,
    backgroundColor: "#65558f",
    borderRadius: 5,
    margin: 5,
  },
  dialogButtonText: {
    color: "white",
    fontSize: 16,
  },
});
