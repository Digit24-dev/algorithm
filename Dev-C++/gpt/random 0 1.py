import random

# 2차원 벡터 크기
rows, cols = 100, 100

# 무작위 2차원 벡터 생성
random_vector = [[random.choice([0, 1]) for _ in range(cols)] for _ in range(rows)]

# 파일에 쓰기
file_path = "./random_vector.txt"
with open(file_path, 'w') as file:
    file.write("{\n")
    for row in random_vector:
        file.write("  {" + ", ".join(map(str, row)) + "},\n")
    file.write("}")

print(f"무작위 벡터가 {file_path} 파일에 저장되었습니다.")
