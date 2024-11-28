def coordinate_compression(coords):
    sorted_unique_coords = sorted(set(coords))
    coord_dict = {coord: index for index, coord in enumerate(sorted_unique_coords)}
    compressed_coords = [coord_dict[coord] for coord in coords]
    return compressed_coords

N = int(input())
coords = list(map(int, input().split()))

compressed_result = coordinate_compression(coords)
print(' '.join(map(str, compressed_result)))
