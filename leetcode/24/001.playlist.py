import heapq
import collecitons
def shuffleSongs(tracks):
    # Store them in dictionary
    library = {}
    for track in tracks:
        songName, artistName = track
        if artistName not in library:
            library[artistName] = []
        library[artistName].append(songName)
        
    # Create a heap to store the artist and his count of songs
    heap = []
    for key in library:
        heapq.heappush(heap, (-len(library[key]), key))
        
    # Continuously pick the highest and add it to the playlist, then pick the next highest without inserting the first.
    previous = None
    playlist = []
    while heap:
        cnt, artist = heapq.heappop(heap)
        cnt = -cnt
        playlist.append((library[artist][0], artist))
        library[artist].pop(0)
        cnt-=1
        
        if previous:
            if previous[0]!=0:
                heapq.heappush(heap, previous)
        previous = (-cnt, artist)
    
    return playlist if len(playlist)==len(tracks) else "Not Possible"
        
tracks = [("songA", "artistA")
        ,("songB", "artistB")
        ,("songB", "artistA")]

print(shuffleSongs(tracks))