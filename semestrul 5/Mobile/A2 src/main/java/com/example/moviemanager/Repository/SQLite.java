package com.example.moviemanager.Repository;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.moviemanager.MovieData;

import java.util.ArrayList;
import java.util.List;

public class SQLite extends SQLiteOpenHelper {
    private static SQLite sqLite;
    private static final String DbName = "MovieDb";
    private static final int DbVers = 1;
    private static final String TableName = "Movie";
    private static final String Counter = "MovieDb";
    private static final String IdField = "Id";
    private static final String TitleField = "Title";
    private static final String GenreField = "Genre";
    private static final String DirectorField = "Director";
    private static final String DescriptionField = "Description";
    private static final String StatusField = "Status";
    private static final String RatingField = "Rating";

    private SQLite(Context context) {
        super(context, DbName, null, DbVers);
    }

    public static SQLite instanceOfDatabase(Context context) {
        if (sqLite == null) {
            sqLite = new SQLite(context);
        }
        return sqLite;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "CREATE TABLE " + TableName + " (" +
                Counter + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                IdField + " INT, " +
                TitleField + " TEXT, " +
                GenreField + " TEXT, " +
                DirectorField + " TEXT, " +
                DescriptionField + " TEXT, " +
                StatusField + " INTEGER, " +
                RatingField + " FLOAT)";
        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
    }

    public void addMovieToDatabase(MovieData movie) {
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(IdField, movie.getId());
        contentValues.put(TitleField, movie.getName());
        contentValues.put(DescriptionField, movie.getDescription());
        contentValues.put(GenreField, movie.getGenre());
        contentValues.put(DirectorField, movie.getDirector());
        contentValues.put(StatusField, movie.getStatus() ? 1 : 0);
        contentValues.put(RatingField, movie.getRating());

        sqLiteDatabase.insert(TableName, null, contentValues);
    }

    public List<MovieData> getAllMovies() {
        SQLiteDatabase sqLiteDatabase = this.getReadableDatabase();
        List<MovieData> movies = new ArrayList<>();
        try (Cursor result = sqLiteDatabase.rawQuery("SELECT * FROM " + TableName, null)) {
            if (result != null && result.getCount() > 0) {
                while (result.moveToNext()) {
                    int id = result.getInt(1);
                    String title = result.getString(2);
                    String descr = result.getString(3);
                    String genre = result.getString(4);
                    String dir = result.getString(5);
                    boolean status = result.getInt(6) == 1;
                    float rating = result.getFloat(7);

                    genre = (genre != null) ? genre : "Unknown";  // Default value if null
                    title = (title != null) ? title : "Untitled";

                    MovieData movie = new MovieData(id, title, genre, status, dir, descr, rating);
                    movies.add(movie);
                }
            }
        }
        return movies;
    }

    public void updateMovieInDb(MovieData movie) {
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(IdField, movie.getId());
        contentValues.put(TitleField, movie.getName());
        contentValues.put(DescriptionField, movie.getDescription());
        contentValues.put(GenreField, movie.getGenre());
        contentValues.put(DirectorField, movie.getDirector());
        contentValues.put(StatusField, movie.getStatus() ? 1 : 0);
        contentValues.put(RatingField, movie.getRating());

        sqLiteDatabase.update(TableName, contentValues, IdField + "=?", new String[]{String.valueOf(movie.getId())});
    }

    public void deleteMovie(Integer Id){
        SQLiteDatabase sqLiteDatabase = this.getWritableDatabase();

        sqLiteDatabase.delete(TableName, IdField + "=?", new String[]{String.valueOf(Id)});
    }
}
