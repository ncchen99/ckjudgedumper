// TODO: fill the route matrix with 0's or 1‘s.
// If there isn't any route, return false; otherwise, return true.
bool visit(char maze[][n], int route[][n], int originX, int originY) {
    int d[4][2] = {{1, 0},
                   {0, 1},
                   {0, -1},
                   {-1, 0}},
        r = 0;
    route[originY][originX] = 1;
    if (originX == n - 1 && originY == n - 1)
        return 1;
    for (int i = 0; i < 4; i++) {
        if (originX + d[i][1] < 0 || originX + d[i][1] >= n || originY + d[i][0] < 0 || originY + d[i][0] >= n)
            continue;
        if (maze[originY + d[i][0]][originX + d[i][1]] == 'r' && !route[originY + d[i][0]][originX + d[i][1]])
            r |= visit(maze, route, originX + d[i][1], originY + d[i][0]);
    }
    if (r)
        return 1;
    route[originY][originX] = 0;
    return 0;
}
