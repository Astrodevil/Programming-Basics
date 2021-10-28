# distance between two points in xy-coourdinate reference system
# can be calculated using euclidean, manhattan and other known
# metrices. however, distance between two points on earth has to
# be calculated using haversine distance, since earth is not flat
# and while calculating distance, the curvature has to be considered.
# the given function calculates haversine distance using `numpy` library
# and is inspired from sklearns haversine distance calculation function:
# https://scikit-learn.org/stable/modules/generated/sklearn.metrics.pairwise.haversine_distances.html

import numpy as np

def haversineDistance(lon1, lat1, lon2, lat2):
    """Calculate the Distance b/w two Geographic Points"""

    dlon = lon2 - lon1 # delta Longitude
    dlat = lat2 - lat1 # delta Latitude

    a = np.sin(dlat/2.0)**2 + np.cos(lat1) * np.cos(lat2) * np.sin(dlon/2.0)**2
    c = 2 * np.arcsin(np.sqrt(a))

    R = 6371 # radius of earth

    return R * c # distance in kilometer


if __name__ == "__main__":
    lon1 = float(input("Enter Point-1's Longitude: "))
    lat1 = float(input("Enter Point-1's Latitude: "))
    lon2 = float(input("Enter Point-2's Longitude: "))
    lat2 = float(input("Enter Point-2's Latitude: "))

    print(f"Distance b/w {lon1, lat1} and {lon2, lat2} is {haversineDistance(lon1, lat1, lon2, lat2)} km.")
