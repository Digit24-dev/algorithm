from _collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    moving_truck = []
    moving_weight = 0
    cnt = 0
    while 1:
        if answer > 1 and len(moving_truck) == 0 and len(truck_weights) == 0:
            break

        answer += 1
        # 트럭 입장
        if moving_weight < truck_weights[cnt]:
            moving_truck.append(truck_weights[cnt])
            moving_weight += truck_weights[cnt]
            cnt += 1

        # 트럭 퇴장
        if answer % bridge_length == 0:
            moving_weight -= moving_truck[0]
            moving_truck.remove(moving_truck[0])

    return answer


bridge_lenth = 2
weight = 10
truck_weights = [7,4,5,6]


print(solution(bridge_lenth, weight, truck_weights))

