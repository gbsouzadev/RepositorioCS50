--write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

--Your query should output a table with a single column for the name of each person.

--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.

--Kevin Bacon himself should not be included in the resulting list.

SELECT DISTINCT name FROM stars JOIN people ON stars.person_id = people.id WHERE movie_id IN (SELECT id FROM movies JOIN stars ON movies.id = stars.movie_id WHERE stars.person_id = (SELECT id FROM people WHERE birth = 1958 AND name = "Kevin Bacon")) AND name != "Kevin Bacon";
