W, H, X, Y, P = map(int, input().split())
R = H/2
answer = 0

def is_in_rectangle(player_X, player_Y):
    if player_X >= X and player_X <= X + W:
        if player_Y >= Y and player_Y <= Y + H:
            return True
    return False

def get_squared_distance(X1, Y1, X2, Y2):
    return (X1 - X2)**2 + (Y1 - Y2)**2

def is_in_circle(player_X, player_Y, circle_X, circle_Y):
    squared_distance = get_squared_distance(player_X, player_Y, circle_X, circle_Y)
    if squared_distance > R**2:
        return False
    return True

for i in range(P):
    player_X, player_Y = map(int, input().split())
    if is_in_rectangle(player_X, player_Y):
        answer += 1
    elif is_in_circle(player_X, player_Y, X, Y + R):
        answer += 1
    elif is_in_circle(player_X, player_Y, X + W, Y + R):
        answer += 1

print(answer)