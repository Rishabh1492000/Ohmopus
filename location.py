import geocoder

def get_location():
    g = geocoder.ip('me')  # Get location based on computer's IP address
    if g.ok:
        location = g.city
        print(f"Location: {location}")
    else:
        print("Unable to retrieve location information.")

get_location()
