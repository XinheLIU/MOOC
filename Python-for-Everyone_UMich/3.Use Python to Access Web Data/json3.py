import json
import urllib

input = '''
[
   {
      "name":"Anaya",
      "count":100
    },
    {
      "name":"Jincheng",
      "count":98
    },
    {
      "name":"Janani",
      "count":97
    },
    {
      "name":"Alishan",
      "count":96
    },
    {
      "name":"Jonson",
      "count":92
    },
    {
      "name":"Odin",
      "count":92
    },
    {
      "name":"Meghan",
      "count":86
    },
    {
      "name":"Sukhvir",
      "count":80
    },
    {
      "name":"Jaeden",
      "count":80
    },
    {
      "name":"Eubha",
      "count":79
    },
    {
      "name":"Rhoridh",
      "count":78
    },
    {
      "name":"Dilan",
      "count":70
    },
    {
      "name":"Stevey",
      "count":66
    },
    {
      "name":"Shivani",
      "count":63
    },
    {
      "name":"Albert",
      "count":56
    },
    {
      "name":"Aneliese",
      "count":56
    },
    {
      "name":"Rihana",
      "count":52
    },
    {
      "name":"Gianluca",
      "count":51
    },
    {
      "name":"Johansson",
      "count":51
    },
    {
      "name":"Teiyib",
      "count":51
    },
    {
      "name":"Ceiran",
      "count":48
    },
    {
      "name":"Liza",
      "count":47
    },
    {
      "name":"Kael",
      "count":45
    },
    {
      "name":"Macsen",
      "count":44
    },
    {
      "name":"Dustin",
      "count":44
    },
    {
      "name":"Pamindar",
      "count":42
    },
    {
      "name":"Meryl",
      "count":40
    },
    {
      "name":"Ihtisham",
      "count":39
    },
    {
      "name":"Tanasha",
      "count":34
    },
    {
      "name":"Nicola",
      "count":29
    },
    {
      "name":"Karissa",
      "count":26
    },
    {
      "name":"Ruslan",
      "count":24
    },
    {
      "name":"Khadijah",
      "count":23
    },
    {
      "name":"Leilah",
      "count":23
    },
    {
      "name":"Riha",
      "count":22
    },
    {
      "name":"Balian",
      "count":19
    },
    {
      "name":"Deegan",
      "count":19
    },
    {
      "name":"Jason",
      "count":17
    },
    {
      "name":"Caolain",
      "count":17
    },
    {
      "name":"Landon",
      "count":17
    },
    {
      "name":"Albie",
      "count":16
    },
    {
      "name":"Msughter",
      "count":14
    },
    {
      "name":"Luciana",
      "count":14
    },
    {
      "name":"Aidan",
      "count":11
    },
    {
      "name":"Indie",
      "count":11
    },
    {
      "name":"Dharam",
      "count":4
    },
    {
      "name":"Mahdiya",
      "count":2
    },
    {
      "name":"Kaylin",
      "count":2
    },
    {
      "name":"Kaela",
      "count":1
    },
    {
      "name":"Kya",
      "count":1
    } 
]'''

info = json.loads(input)
sum=0

for item in info:

    n=item['count']
    sum=sum+n
print sum

