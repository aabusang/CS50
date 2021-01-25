SELECT title, rating FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id
AND year = 2010 ORDER BY rating DESC, title;