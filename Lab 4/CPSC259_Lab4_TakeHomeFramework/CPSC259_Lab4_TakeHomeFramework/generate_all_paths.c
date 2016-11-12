void generate_all_paths(
  maze_cell ** maze,
  int dimension,
  int row, int column,
  char * path
) {
  // local variables
  int path_length  = 0;
  char * new_point = NULL;
  char * new_path  = NULL;

  // base cases
  if (row    > dimension - 1 ||
      row    < 0             ||
      column > dimension - 1 ||
      column < 0             ||
      maze[row][column].character == MAZE_WALL ||
      maze[row][column].visited   == VISITED) return;

  else {
    // get length of existing path
    path_length = strlen(path);

    // allocate space for a larger new path
    new_path = (char *)calloc(path_length + 2, sizeof(char));
    // allocate space for a new point to add to path
    new_point = (char *)calloc(2, sizeof(char));

    // assign the value in the maze cell to new point
    new_point[0] = maze[row][column].character;

    // concatenate old path to new path
    if (path_length) {
      new_path = strcat(new_path, path);
    }

    // concat new pt to new path
    new_path = strcat(new_path, new_point);

    if (column == (dimension - 1)) {
      // at the end of maze
      // reallocate mem to make room for a new solution
      paths = (char **)realloc(paths, (paths_found + 1) * sizeof(char *));
      paths[paths_found] = (char *)calloc(strlen(new_path) + 1, sizeof(char));

      // copy the solution to the newly allocated mem
      strcpy(paths[paths_found], new_path);

      // increment path counter
      paths_found++;
      return
    } else {
      // not at the end
      // mark point as visited
      maze[row][column].visited = VISITED;

      // recursively explore nearby
      generate_all_paths(maze, dimension, row, column + 1, new_path);
      generate_all_paths(maze, dimension, row, column - 1, new_path);
      generate_all_paths(maze, dimension, row + 1, column, new_path);
      generate_all_paths(maze, dimension, row - 1, column, new_path);

      // mark point as unvisited
      maze[row][column].visited = UNVISITED;
      return;
    }
  }
}
