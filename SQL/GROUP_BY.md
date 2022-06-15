## Group by
Sometimes I get messed up with `group by`, so I record some group by problems for a better understanding of `group by`

## Problem 1
Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent) and their respective average city populations (CITY.Population) rounded down to the nearest integer.

Note: CITY.CountryCode and COUNTRY.Code are matching key columns.

CITY:
|Field|Type|
|---|---|
|ID|NUMBER|
|NAME|VARCHAR2(17)|
|COUNTRYCODE|VARCHAR2(3)|
|DISTRICT|VARCHAR2(20)|
|POPULATION|NUMBER|

COUNTRY:
|Field|Type|
|---|---|
|CODE|VARCHAR2(3)|
|NAME|VARCHAR2(44)|
|CONTINENT|VARCHAR(13)|
|REGION|VARCHAR(25)|
|POPULATION|NUMBER|

## Solution
```sql
select country.continent, floor(avg(city.population))
from city inner join country
on city.countrycode = country.code
group by country.continent;
```