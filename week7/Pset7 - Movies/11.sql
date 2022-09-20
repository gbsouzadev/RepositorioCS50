-- write a SQL query to list the titles of the five highest rated movies (in order) that
-- Chadwick Boseman starred in, starting with the highest rated.

-- Your query should output a table with a single column for the title of each movie.

-- You may assume that there is only one person in the database with the name Chadwick Boseman.

SELECT title FROM movies JOIN stars JOIN people JOIN ratings ON stars.movie_id = movies.id AND stars.person_id = people.id AND ratings.movie_id = movies.id WHERE name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;
