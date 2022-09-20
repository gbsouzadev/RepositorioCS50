-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28;
    --description

    --Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with
    --three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

        --Vandalism took place at 12:04. No known witnesses.
        --Shoplifting took place at 03:01. Two people witnessed the event.
        --Money laundering took place at 20:30. No known witnesses.
        --Littering took place at 16:36. No known witnesses.

SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28;
    -- Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the
    -- thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end
    -- of the phone to purchase the flight ticket.

    -- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking
    -- by the ATM on Leggett Street and saw the thief there withdrawing some money.

    -- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security
    -- footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

        -- Lily | Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster
        -- to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.

        -- Barbara | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked
        -- from one to the other of us, as if uncertain which to address.

SELECT account_number, transaction_type FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28;
--28500762 | withdraw
--28296815 | withdraw
--76054385 | withdraw
--49610011 | withdraw
--16153065 | withdraw
    --86363979 | deposit
--25506511 | withdraw
--81061156 | withdraw
--26013199 | withdraw

SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28) AND NOT 86363979;
-- Bruce
-- Kaelyn (deposit)
-- Diana
-- Brooke
-- Kenny
-- Iman
-- Luca
-- Taylor
-- Benista

SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number = 86363979;
-- Kaelyn

SELECT id, caller FROM phone_calls WHERE month = 7 AND day = 28;
id | caller
--211 | (336) 555-0077
--212 | (918) 555-5327
--213 | (491) 555-2505
--214 | (996) 555-8899
--215 | (704) 555-5790
--216 | (984) 555-5921
--217 | (579) 555-5030
--218 | (233) 555-0473
--219 | (293) 555-1469
--220 | (450) 555-8297
--221 | (130) 555-0289
--222 | (209) 555-7806
--223 | (918) 555-2946
--224 | (499) 555-9472
--225 | (669) 555-6918
--226 | (547) 555-8781
--227 | (544) 555-8087
--228 | (666) 555-5774
--229 | (047) 555-0577
--230 | (301) 555-4174
--231 | (801) 555-9266
--232 | (971) 555-6468
--233 | (367) 555-5533
--234 | (609) 555-5876
--235 | (357) 555-0246
--236 | (367) 555-5533
--237 | (394) 555-3247
--238 | (839) 555-1757
--239 | (770) 555-1196
--240 | (636) 555-4198
--241 | (068) 555-0183
--242 | (711) 555-3007
--243 | (060) 555-2489
--244 | (704) 555-2131
--245 | (367) 555-5533
--246 | (873) 555-3868
--247 | (867) 555-9103
--248 | (608) 555-9302
--249 | (901) 555-8732
--250 | (478) 555-1565
--251 | (499) 555-9472
--252 | (695) 555-0348
--253 | (696) 555-9195
--254 | (286) 555-6063
--255 | (770) 555-1861
--256 | (711) 555-3007
--257 | (725) 555-4692
--258 | (324) 555-0416
--259 | (234) 555-1294
--260 | (669) 555-6918
--261 | (031) 555-6622
--262 | (342) 555-9260
--263 | (342) 555-9260
--264 | (801) 555-9266
--265 | (398) 555-1013
--266 | (016) 555-9166
--267 | (594) 555-2863
--268 | (122) 555-4581
--269 | (914) 555-5994
--270 | (258) 555-5627
--271 | (751) 555-6567
--272 | (771) 555-7880
--273 | (219) 555-0139
--274 | (676) 555-6554
--275 | (749) 555-4874
--276 | (328) 555-9658
--277 | (219) 555-0139
--278 | (380) 555-4380
--279 | (826) 555-1652
--280 | (594) 555-6254
--281 | (338) 555-6650
--282 | (971) 555-6468
--283 | (730) 555-5115
--284 | (286) 555-6063
--285 | (367) 555-5533
--286 | (041) 555-4011
--287 | (478) 555-1565

SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26;
--260 | 2021 | 7 | 28 | 10 | 16 | exit | 5P2BI95
--261 | 2021 | 7 | 28 | 10 | 18 | exit | 94KL13X
--262 | 2021 | 7 | 28 | 10 | 18 | exit | 6P58WS2
--263 | 2021 | 7 | 28 | 10 | 19 | exit | 4328GD8
--264 | 2021 | 7 | 28 | 10 | 20 | exit | G412CB7
--265 | 2021 | 7 | 28 | 10 | 21 | exit | L93JTIZ
--266 | 2021 | 7 | 28 | 10 | 23 | exit | 322W7JE
--267 | 2021 | 7 | 28 | 10 | 23 | exit | 0NTHK55

SELECT name, license_plate FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26);
--name | license_plate
--Vanessa | 5P2BI95
--Barry | 6P58WS2
--Iman | L93JTIZ
--Sofia | G412CB7
--Luca | 4328GD8
--Diana | 322W7JE
--Kelsey | 0NTHK55
--Bruce | 94KL13X

SELECT name, license_plate FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26) AND name IN (SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28));
-- name | license_plate
    -- Iman | L93JTIZ
-- Luca | 4328GD8
-- Diana | 322W7JE
-- Bruce | 94KL13X

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE flights.day = 29 AND flights.month = 7 AND flights.origin_airport_id = 8 ORDER BY name;


SELECT name FROM people
WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26) AND name IN (SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28)))
AND name IN (SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id JOIN airports ON flights.origin_airport_id = airports.id WHERE flights.day = 29 AND flights.month = 7 AND flights.origin_airport_id = 8)
ORDER BY name;
--name
--Bruce
--Diana
--Luca

SELECT name, phone_number FROM people WHERE name IN (SELECT name FROM people
WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26) AND name IN (SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28)))
AND name IN (SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id JOIN airports ON flights.origin_airport_id = airports.id WHERE flights.day = 29 AND flights.month = 7 AND flights.origin_airport_id = 8));
--name | phone_number
--Luca | (389) 555-5198
--Diana | (770) 555-1861
--Bruce | (367) 555-5533

SELECT name, caller FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE month = 7 AND day = 28
AND name IN (SELECT name FROM people WHERE name IN (SELECT name FROM people WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND minute > 14 AND minute < 26) AND name IN (SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Leggett Street" AND month = 7 AND day = 28))) AND name IN (SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id JOIN airports ON flights.origin_airport_id = airports.id WHERE flights.day = 29 AND flights.month = 7 AND flights.origin_airport_id = 8)));
--name | caller
--Bruce | (367) 555-5533
--Bruce | (367) 555-5533
--Bruce | (367) 555-5533
--Diana | (770) 555-1861
--Bruce | (367) 555-5533

SELECT id, receiver, duration FROM phone_calls WHERE month = 7 AND day = 28 AND caller = "(367) 555-5533" AND duration < 60;
-- People who Bruce called to:
-- id | receiver | duration
-- 233 | (375) 555-8161 | 45

SELECT name FROM people WHERE phone_number = "(375) 555-8161";
--name
--Robin

SELECT id, receiver, duration FROM phone_calls WHERE month = 7 AND day = 28 AND caller = "(770) 555-1861" AND duration < 60;
-- People who Diana called to:
--id | receiver | duration
--255 | (725) 555-3243 | 49

SELECT id, hour, minute FROM flights WHERE day = 29 AND month = 7 AND origin_airport_id = 8 ORDER BY hour;
--id | hour | minute

--36 | 8 | 20

    --43 | 9 | 30
    --23 | 12 | 15
    --53 | 15 | 20
    --18 | 16 | 0

SELECT passport_number FROM people where name = "Diana";
--passport_number
--3592750733

SELECT passport_number FROM people where name = "Bruce";
--passport_number
--5773159633


SELECT passport_number FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE id = 36 AND day = 29 AND month = 7;
--passport_number
--7214083635
--1695452385
            --5773159633 That's Bruce
--1540955065
--8294398571
--1988161715
--9878712108
--8496433585

SELECT city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.id = 36 AND flights.day = 29 AND flights.month = 7;
--city
--New York City
