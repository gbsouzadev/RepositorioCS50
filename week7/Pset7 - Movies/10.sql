-- write a SQL query to list the names of all people who have directed a
-- movie that received a rating of at least 9.0.

-- Your query should output a table with a single column for the name of each person.

-- If a person directed more than one movie that received a rating of at least 9.0, they
-- should only appear in your results once.

SELECT DISTINCT name FROM people JOIN directors JOIN movies JOIN ratings ON directors.person_id = people.id AND directors.movie_id = movies.id AND ratings.movie_id = movies.id WHERE rating >= 9.0;