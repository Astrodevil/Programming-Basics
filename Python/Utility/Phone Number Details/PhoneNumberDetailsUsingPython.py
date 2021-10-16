import phonenumbers as ph
from phonenumbers import carrier
from phonenumbers import geocoder
from phonenumbers import timezone

number = input("Enter Phone Number: ") 
number = ph.parse(number)
print("Time Zone: ",timezone.time_zones_for_number(number))
print("Carrier Name: ",carrier.name_for_number(number, "en"))
print("Location: ",geocoder.description_for_number(number, "en"))