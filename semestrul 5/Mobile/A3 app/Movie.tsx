export default class Movie {
    id:number;
  title: string;
  genre: string;
  seen: boolean;
  director?: string;
  description?: string;
  rating?: number;
  constructor(
    id:number,
    title: string,
    genre: string,
    seen: boolean,
    director?: string,
    description?: string,
    rating?: number
  ) {
    this.id=id;
    this.title = title;
    this.genre = genre;
    this.seen = seen;
    this.director = director;
    this.description = description;
    this.rating = rating;
  }
}
