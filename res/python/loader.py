from py_linq import Enumerable
import json
import rgb565converter
from ldtkpy.api import ldtk_json_from_dict

baseDir = 'demo1/'

f = open(baseDir + "demo1.json", "r")
result = ldtk_json_from_dict(json.loads(f.read()))
f.close() 

#entities
for tileSet in result.defs.tilesets:
    if (tileSet.identifier=='Sprites'):
        print(tileSet.rel_path)
        f = open(baseDir + tileSet.rel_path, "r")
        print(tileSet.identifier)
        f.close() 
        #print(tileSet.to_dict())
        
#for entity in result.defs.layers:
#    print(entity.grid_size)

#exit()

#levels
tile_index = 0
cell_index = 0

for level in result.levels:
    print('lv.name = "',level.identifier,'";')
    for layer_instance in level.layer_instances:
        
        print('----------------------------------')
        #print(layer_instance.identifier)
        
        if (layer_instance.type=='Tiles'):
            
            #create sprites
            print('#pragma region cells sprites')
            #print(layer_instance.tileset_rel_path)

            usedTiles = Enumerable(layer_instance.grid_tiles).distinct(lambda x: x.t).to_list()
            for tile in usedTiles:
                rgb565converter.convert_to_c(baseDir + layer_instance.tileset_rel_path, 'tile_' + str(tile.t), tile.src[0], tile.src[1], 16, 16)
            
            print('#pragma endregion')            
            #exit()                
            
            #create array
            print('#pragma region cells')
            print('lv.cells_count=',len(layer_instance.grid_tiles),';')
            print('lv.cells2 = new cell[lv.cells_count];')
            for tile in layer_instance.grid_tiles:
                print('lv.cells2[',tile_index,'] = {{',tile.px[0],', ',tile.px[1],'}, tile_' + str(tile.t) + '};')
                tile_index += 1
            print('#pragma endregion')

        if (layer_instance.type=='IntGrid'):
            print('#pragma region collisions')
            for i in range(len(layer_instance.int_grid_csv)):
                y = i // layer_instance.c_wid
                x = i - (y * layer_instance.c_wid)
                if (layer_instance.int_grid_csv[i] == 1): #block                
                    print('lv.collisions[',cell_index,'] = {{',x*layer_instance.grid_size,', ',y*layer_instance.grid_size,'}, {',x*layer_instance.grid_size+16,', ',y*layer_instance.grid_size+16,'}};')
                    cell_index += 1
            print('lv.collisions_count=',cell_index,';')
            print('#pragma endregion')
