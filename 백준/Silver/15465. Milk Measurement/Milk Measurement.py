import sys

def count_display_changes(n, measurements):
    milk_output = {"Bessie": 7, "Elsie": 7, "Mildred": 7}
    log = []
    
    for measurement in measurements:
        day, cow, change = measurement.split()
        log.append((int(day), cow, int(change)))
    
    log.sort()
    
    display_changes = 0
    prev_display = set(milk_output.keys()) 
    
    for day, cow, change in log:
        milk_output[cow] += change
        
        max_milk = max(milk_output.values())
        new_display = {c for c, m in milk_output.items() if m == max_milk}
        
        if new_display != prev_display:
            display_changes += 1
            prev_display = new_display
    
    return display_changes

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    measurements = [sys.stdin.readline().strip() for _ in range(n)]
    print(count_display_changes(n, measurements))
