class Queue {
  constructor() {
    this.items = [];
  }
  enqueue(element) {
    this.items.push(element);
  }
  dequeue() {
    if (this.isEmpty()) return "Underflow";
    return this.items.shift();
  }

  isEmpty() {
    return this.items.length == 0;
  }
}
class Stack {
  constructor() {
    this.items = [];
  }
  push(element) {
    this.items.push(element);
  }
  pop() {
    if (this.items.length == 0) return "Underflow";
    return this.items.pop();
  }
  isEmpty() {
    return this.items.length == 0;
  }
}
let graphAdj;
let visited;
let stack;

const initGraph = (totVertices) => {
  visited = new Array(totVertices);

  queue = new Queue();
  stack = new Stack();

  for (let i = 0; i < visited.length; i++) {
    visited[i] = false;
  }
  graphAdj = new Array(totVertices);
  for (let i = 0; i < graphAdj.length; i++) {
    graphAdj[i] = new Array(totVertices);
  }
  for (let i = 0; i < graphAdj.length; i++) {
    for (let j = 0; j < graphAdj[i].length; j++) {
      graphAdj[i][j] = 0;
    }
  }
};

const adjMatrix = (a, b) => {
  for (let i = 0; i < graphAdj.length; i++) {
    for (let j = 0; j < graphAdj[i].length; j++) {
      if (i == a && j == b) {
        graphAdj[i][j] = 1;
        graphAdj[j][i] = 1;
      }
    }
  }
};

const breadthFirstSearch = (node, final) => {
  visited[node] = true;
  queue.enqueue(node);
  console.log("BFS-------------");
  console.log(`Starting Node is: ${node}`);
  console.log(`Final Node is: ${final}`);
  while (!queue.isEmpty()) {
    let currentNode = queue.dequeue();
    console.log(`We are currently at: ${currentNode}`);
    if (currentNode === final) {
      console.log("Found the node :)");
      return;
    }
    for (let j = 0; j < graphAdj[currentNode].length; j++) {
      if (graphAdj[currentNode][j] === 1 && visited[j] === false) {
        visited[j] = true;
        queue.enqueue(j);
      }
    }
  }
  console.log(`Sorry please check your final node, we checked all nodes`);
};

const depthFirstSearch = (node, final) => {
  stack.push(node);
  console.log("DFS-------------");

  console.log(`Starting Node is: ${node}`);
  console.log(`Final Node is: ${final}`);
  while (!stack.isEmpty()) {
    node = stack.pop();
    if (visited[node] == false) {
      visited[node] = true;
      console.log(`We are currently at: ${node}`);
      if (node === final) {
        console.log("Found the node :)");
        return;
      }
      for (let j = 0; j < graphAdj[node].length; j++) {
        if (graphAdj[node][j] === 1) {
          stack.push(j);
        }
      }
    }
  }
  console.log(`Sorry please check your final node, we checked all nodes`);
};

//Adding Total Vertices
initGraph(7);

//Adding Edges
adjMatrix(1, 3);
adjMatrix(1, 4);
adjMatrix(1, 2);
adjMatrix(3, 4);
adjMatrix(4, 2);
adjMatrix(2, 5);
adjMatrix(5, 4);

// breadthFirstSearch(1, 6);
depthFirstSearch(1, 6);
