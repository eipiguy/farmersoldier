class Location:
    def __init__( self, x, y ):
        self.coordinates = [ x, y ]
        self.neighbors = []
    
    def add_neighbor( self, new_neighbor ):
        self.neighbors.append(new_neighbor)
        pass

class RectangularBoard:
    def rasterize( self, x, y ):
        return x*self.row_size + y

    def get_coordinates( self, i ):
        return self.board_locations[i].coordinates

    def __init__( self, n ):
        self.row_size = n
        self.board_locations = []
        for x in range(n):
            for y in range(n):
                self.board_locations.append(Location(x,y))

    def location_exists( self, x, y ):
        return self.rasterize(x,y) < len(self.board_locations)

    def get_location( self, x, y ):
        return self.board_locations[self.rasterize(x,y)]

    def connect_locations_rectangular( self ):
        for x in range(self.row_size-1):
            for y in range((len(self.board_locations) // self.row_size)-1):
                self.get_location(x,y).add_neighbor(self.get_location(x+1, y))
                self.get_location(x,y).add_neighbor(self.get_location(x, y+1))

    def north_neighbor( self, this_location ):
        return self.get_location(this_location.coordinates[0], this_location.coordinates[1]+1)

    def south_neighbor( self, this_location ):
        return self.get_location(this_location.coordinates[0], this_location.coordinates[1]-1)

    def east_neighbor( self, this_location ):
        return self.get_location(this_location.coordinates[0]+1, this_location.coordinates[1])

    def west_neighbor( self, this_location ):
        return self.get_location(this_location.coordinates[0]-1, this_location.coordinates[1])