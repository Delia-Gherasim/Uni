import Movie from './Movie';
export default function Repository() {
  const movies: Movie[] = [
    new Movie(1, "title1", "genre1", false, "director1", "description"),
    new Movie(2, "title2", "genre2", true, "director1", undefined, 2.5),
    new Movie(3, "title3", "genre3", false, "director1", "description"),
    new Movie(4, "title4", "genre4", true, undefined, "description", 4.9),
  ];

  return movies;
}
