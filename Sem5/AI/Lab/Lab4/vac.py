# create matrix floor that contains dirty and clean tiles

floor = [[1, 0, 0, 0], 
         [0, 1, 0, 1],
         [1, 0, 1, 1]]


def clean(floor):
    m = len(floor[0]) 
    n = len(floor)    
    no_of_tiles = m * n

    tiles_checked = 0

    row = 0
    col = 0
    while tiles_checked < no_of_tiles:
        #Current location of vaccum cleaner
        print_floor(floor, row, col)

        
        if floor[row][col] == 1:
            floor[row][col] = 0
            print('Cleaning')
        else:
            print('Already Clean')
        
    
 
        if row % 2 == 0:         
            if col < m-1:
                col += 1
            else:
                row += 1  
        
        elif row % 2 == 1:        
            if 0 < col:
                col -= 1
            else:
                row += 1  
        
        tiles_checked += 1

    
    print('Clean')
        

        
def print_floor(floor, row, col):
    temp = floor[row][col]
    floor[row][col] = 'VC'
    for x in floor:
        print(x)
    
    floor[row][col] = temp


clean(floor) 