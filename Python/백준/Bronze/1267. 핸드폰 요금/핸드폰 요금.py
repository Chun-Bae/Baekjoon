def calculate_phone_bill():
    N = int(input())  
    call_times = list(map(int, input().split()))
    youngsik = sum((time // 30 + 1) * 10 for time in call_times)
    minsik = sum((time // 60 + 1) * 15 for time in call_times)

    if youngsik < minsik:
        print(f"Y {youngsik}")
    elif youngsik > minsik:
        print(f"M {minsik}")
    else:
        print(f"Y M {youngsik}")

calculate_phone_bill()