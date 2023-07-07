import board, pieces

board_size = 3
main_board = board.RectangularBoard(board_size)
main_board.connect_locations_rectangular()
main_board.print()

P0_pieces = []
P1_pieces = []

P0_pieces.append(pieces.Child(0, main_board[0]))
P1_pieces.append(pieces.Child(1, main_board[len(main_board.board_locations)-1]))