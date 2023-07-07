import board

class Child:
	def __init__( self, player, location ):
		self.player = player
		self.location = location
		return

class Farmer(Child):
	def __init__( self ):
		pass


class Soldier(Child):
	pass

class PieceProgression:
	def __init__( self ):
		self.turn = -1
		self.pieces = []
		return