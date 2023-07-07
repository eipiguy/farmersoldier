class Location:
	def __init__( self, x, y ):
		self.coordinates = ( x, y )
		self.neighbors = {}
		self.id = -1

	def __getitem__( self, key ):
		return self.neighbors[key]

	def __setitem__(self, key, rhs):
		self.neighbors[key] = rhs

	def add_neighbor( self, new_key, new_neighbor ):
		self.neighbors[new_key] = new_neighbor

	def print_neighbors( self ):
		print(f"(x,y) = {self.coordinates}")
		print(f"neighbors =")
		for neighbor_key in self.neighbors:
				neighbor_coordinates = self[neighbor_key].coordinates
				print(f"    {neighbor_key} [i={self.rasterize(neighbor_coordinates[0], neighbor_coordinates[1])}] = {neighbor_coordinates}")

class RectangularBoard:
	def __init__( self, n ):
		self.row_size = n
		self.board_locations = []
		for x in range(n):
			for y in range(n):
				self.board_locations.append(Location(x,y))

	def __getitem__( self, key ):
		return self.board_locations[key]

	def location_exists( self, x, y ):
		return x >= 0 and x < (len(self.board_locations) // self.row_size) and y >= 0 and y < self.row_size

	def rasterize( self, x, y ):
		return x*self.row_size + y

	def get_location( self, x, y ):
		return self[self.rasterize(x,y)]

	def connect_locations_rectangular( self ):
		for x in range(self.row_size):
			for y in range(len(self.board_locations) // self.row_size):
				if self.location_exists(x+1, y):
					self.get_location(x,y)['E'] = self.get_location(x+1,y)
					self.get_location(x+1,y)['W'] = self.get_location(x,y)
				if self.location_exists(x, y+1):
					self.get_location(x,y)['N'] = self.get_location(x,y+1)
					self.get_location(x,y+1)['S'] = self.get_location(x,y)

	def print( self ):
		for i, location in enumerate(self.board_locations):
			print(f"\nBoard Location [i = {i}] = {location.coordinates}")
			for neighbor in location.neighbors:
				neighbor_coordinates = location[neighbor].coordinates
				print(F"    {neighbor} [i={self.rasterize(neighbor_coordinates[0], neighbor_coordinates[1])}] = {neighbor_coordinates}")