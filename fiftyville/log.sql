-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND year = 2021 AND month = 7 AND day = 28;

SELECT * FROM interviews
WHERE transcript LIKE '%bakery%';


--people who left the bakery
SELECT name,phone_number,passport_number,people.license_plate FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.id IN(SELECT id FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour>=10 AND minute<30 AND hour<11
AND activity = 'exit')
ORDER BY name;


--people who withdrew
SELECT name,phone_number,passport_number,people.license_plate FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.id IN(SELECT id FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street')
ORDER BY name;


--people who called
SELECT name,phone_number,passport_number,people.license_plate,receiver FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration<60;

--flight that suspect will take
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE year = 2021 AND day = 29
AND airports.full_name LIKE '%Fiftyville%'
ORDER BY hour,minute
LIMIT 1;

--people on the flight suspect is is taking
SELECT name,phone_number,people.passport_number,people.license_plate FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id IN(SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE year = 2021 AND day = 29
AND airports.full_name LIKE '%Fiftyville%'
ORDER BY hour,minute
LIMIT 1);


--query to search common people
SELECT name,phone_number,passport_number,people.license_plate FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.id IN(SELECT id FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour>=10 AND minute<30 AND hour<11
AND activity = 'exit')
AND people.name IN(SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.id IN(SELECT id FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street'))
AND people.name IN(SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration<60)
AND people.name IN (SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id IN(SELECT flights.id FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE year = 2021 AND day = 29
AND airports.full_name LIKE '%Fiftyville%'
ORDER BY hour,minute
LIMIT 1));
--QUERY COMPLETED! SUSPECT IS  BRUCE!