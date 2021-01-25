
-- SELECT title FROM movies AS t
-- JOIN ratings AS r ON t.id = r.movie_id
-- WHERE r.movie_id IN
-- (SELECT movie_id FROM stars
-- WHERE person_id IN
-- (SELECT id FROM people
-- WHERE name = "Chadwick Boseman")) ORDER BY r.rating DESC LIMIT 5;

SELECT title FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.movie_id IN
(SELECT movie_id FROM stars
WHERE person_id IN
(SELECT id FROM people
WHERE name = "Chadwick Boseman")) ORDER by ratings.rating DESC LIMIT 5;

-- SELECT title FROM movies WHERE id IN
-- (SELECT movie_id FROM ratings WHERE movie_id IN
-- (SELECT movie_id FROM stars WHERE person_id IN
-- (SELECT id FROM people WHERE name = "Chadwick Boseman"))) LIMIT 5;