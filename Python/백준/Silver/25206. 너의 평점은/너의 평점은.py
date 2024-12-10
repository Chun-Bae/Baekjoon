grade_to_point = {
    "A+": 4.5, "A0": 4.0,
    "B+": 3.5, "B0": 3.0,
    "C+": 2.5, "C0": 2.0,
    "D+": 1.5, "D0": 1.0,
    "F": 0.0
}

total_credits = 0.0
total_points = 0.0

for _ in range(20):
    subject, credit, grade = input().split()
    credit = float(credit)
    if grade != "P":
        total_credits += credit
        total_points += credit * grade_to_point.get(grade, 0.0)

if total_credits > 0:
    major_gpa = total_points / total_credits
else:
    major_gpa = 0.0

print(f"{major_gpa:.6f}")
