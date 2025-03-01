import { Picker } from '@react-native-picker/picker';
import React, { useEffect, useState } from 'react';
import { Alert, ScrollView, StyleSheet, Switch, Text, TextInput, TouchableOpacity, View } from 'react-native';
import Movie from './Movie';

interface EditProps {
  movie: Movie;
  onEdit: (movie: Movie) => void;
  onBack: () => void;
}

export default function Edit({ movie, onEdit, onBack }: EditProps) {
  const [title, setTitle] = useState(movie.title);
  const [description, setDescription] = useState(movie.description || "");
  const [genre, setGenre] = useState(movie.genre);
  const [director, setDirector] = useState(movie.director || "");
  const [seen, setSeen] = useState(movie.seen);
  const [rating, setRating] = useState<number>(movie.rating || 0);

  useEffect(() => {
    setTitle(movie.title);
    setDescription(movie.description || "");
    setGenre(movie.genre);
    setDirector(movie.director || "");
    setSeen(movie.seen);
    setRating(movie.rating || 0);
  }, [movie]);

  const handleBack = () => {
    onBack();
  };

  const handleRatingChange = (value: string) => {
    if (value === '' || /^(\d+(\.\d{0,1})?)?$/.test(value)) {
      setRating(value === '' ? 0 : parseFloat(value));
    }
  };

  const handleEdit = () => {
    if (!title.trim()) {
      Alert.alert('Validation Error', 'Title is required.');
      return;
    }
    if (seen && (rating < 1 || rating > 5)) {
      Alert.alert('Validation Error', 'Rating must be between 1 and 5.');
      return;
    }
    const updatedMovie = new Movie(
      movie.id, 
      title,
      genre,
      seen,
      director || undefined,
      description || undefined,
      rating
    );
    onEdit(updatedMovie);
  };

  return (
    <ScrollView contentContainerStyle={styles.container}>
      <TouchableOpacity style={styles.goBackButton} onPress={handleBack}>
        <Text style={styles.goBackButtonText}>&#8592; Back</Text>
      </TouchableOpacity>

      {/* Form */}
      <View style={styles.form}>
        <View style={styles.field}>
          <Text style={styles.label}>Title:</Text>
          <TextInput
            value={title}
            onChangeText={setTitle}
            style={styles.input}
          />
        </View>

        <View style={styles.field}>
          <Text style={styles.label}>Director:</Text>
          <TextInput
            value={director}
            onChangeText={setDirector}
            style={styles.input}
          />
        </View>

        <View style={styles.field}>
          <Text style={styles.label}>Genre:</Text>
          <Picker
            selectedValue={genre}
            onValueChange={(itemValue: string) => setGenre(itemValue)}
            style={styles.picker}
          >
            <Picker.Item label="Select a genre" value="" />
            <Picker.Item label="Action" value="Action" />
            <Picker.Item label="Comedy" value="Comedy" />
            <Picker.Item label="Drama" value="Drama" />
            <Picker.Item label="Horror" value="Horror" />
            <Picker.Item label="Romance" value="Romance" />
            <Picker.Item label="Sci-Fi" value="Sci-Fi" />
            <Picker.Item label="Thriller" value="Thriller" />
            <Picker.Item label="Fantasy" value="Fantasy" />
            <Picker.Item label="Documentary" value="Documentary" />
            <Picker.Item label="Animation" value="Animation" />
          </Picker>
        </View>

        <View style={styles.field}>
          <Text style={styles.label}>Description:</Text>
          <TextInput
            value={description}
            onChangeText={setDescription}
            style={[styles.input, styles.textarea]}
            multiline
          />
        </View>

        <View style={styles.fieldCheckbox}>
          <Text style={styles.label}>I have seen this film</Text>
          <Switch
            value={seen}
            onValueChange={setSeen}
          />
        </View>

        {seen && (
          <View style={styles.field}>
            <Text style={styles.label}>Rating (out of 5):</Text>
            <TextInput
              value={rating?.toString() || ''}
              onChangeText={handleRatingChange} 
              style={styles.input}
              keyboardType="numeric"
            />
          </View>
        )}

        <TouchableOpacity style={styles.saveButton} onPress={handleEdit}>
          <Text style={styles.saveButtonText}>Save</Text>
        </TouchableOpacity>
      </View>
    </ScrollView>
  );
}

const styles = StyleSheet.create({
  container: {
    padding: 20,
    flexGrow: 1,
  },
  goBackButton: {
    marginBottom: 20,
    padding: 10,
    backgroundColor: '#EADDFF',
    borderRadius: 5,
    alignItems: 'center',
  },
  goBackButtonText: {
    fontSize: 16,
    color: '#333',
  },
  form: {
    flexDirection: 'column',
  },
  field: {
    marginBottom: 15,
  },
  label: {
    fontSize: 14,
    fontWeight: 'bold',
    marginBottom: 5,
  },
  input: {
    borderWidth: 1,
    borderColor: '#ccc',
    borderRadius: 5,
    padding: 10,
    fontSize: 16,
  },
  textarea: {
    height: 80,
  },
  picker: {
    borderWidth: 1,
    borderColor: '#ccc',
    borderRadius: 5,
    padding: 10,
  },
  fieldCheckbox: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    marginBottom: 15,
  },
  saveButton: {
    padding: 10,
    backgroundColor: '#65558f',
    borderRadius: 5,
    alignItems: 'center',
  },
  saveButtonText: {
    color: '#fff',
    fontSize: 16,
  },
});
