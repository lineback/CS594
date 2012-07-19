package main

import(
	"fmt"
        "strings"
        "io/ioutil"
        "os"
        "sort"
)
// a data structure for a vertex
type Vertex struct {
	id     int       // the id of the vertex
	dist   int       // the distance to the vertex from the source
	parent int       // the vertex's parent node in the spanning tree
	nbr    []int     // the vertex's neighbors
}

// this data type will allow sorting (notice the use of pointers)
type Vertices []*Vertex

// the next three functions implement the sort interface
func (v Vertices) Len() int {
	return len(v)
}

func (v Vertices) Swap(i, j int) {
	v[i], v[j] = v[j], v[i]
}

func (v Vertices) Less(i, j int) bool{
	return v[i].dist < v[j].dist 
}

// does ints contain i
func Contains(ints []int, i int) bool {
	for _,val := range ints {
		if val == i {
			return true 
		}
	}
	return false
}

func main(){
	// check the command line arguments
	if len(os.Args) != 4 {
		panic("Usage: ./dijkstra FILENAME SOURCE DEST")
	}
	var source int             
	var dest int
	fmt.Sscan(os.Args[2], &source)
	fmt.Sscan(os.Args[3], &dest)
	fileName := os.Args[1]
	
	// read in data from file
	buff,_ := ioutil.ReadFile(fileName)
	contentString := string(buff)
	lines := strings.Split(contentString, "\n")
	
	var numVert int  // number of vertices
	fmt.Sscan(lines[0], &numVert)
	// our adjacency matrix
	adjMat := make([][]int, numVert)         // this is similar to new or malloc 
	for i:= 0; i < numVert; i++ {
		adjMat[i] = make([]int, numVert)
	}
	// convert data from string to integer and error check
	for i := 1; i<numVert + 1; i++ {
		toks := strings.Split(lines[i], " ")
		if len(toks) != numVert {
			panic("Invalid File")
		}
		for j := 0; j < numVert; j++ {
			fmt.Sscan(toks[j], &adjMat[i -1][j])
		}
	}
		
	pQueue := make([]*Vertex, numVert)    // our priority queue
	vertList := make([]*Vertex, numVert)  // our list of vertices for fast access
	var vertTree []int                    // our list of vertices in the tree
	
	// set up the vertices
	for i:=0; i<numVert; i++{
		newVertex := new(Vertex)
		newVertex.id = i
		newVertex.dist = 1e8   // initialize it to be really big
		newVertex.parent = -1  // initialize to a nonsense value
		// get the neighbors
		for j:=0; j<numVert; j++{
			if adjMat[i][j] != 0 {
				newVertex.nbr = append(newVertex.nbr, j)
			}
		}
		// add the vertex to the queue and the list
		pQueue[i] = newVertex
		vertList[i] = newVertex
	}
	
	// now we get to the business end of the program
	// set the source to have distance 0
	vertList[source].dist = 0
	// since we used pointers the update is reflected in the queue
	// sort the queue
	sort.Sort(Vertices(pQueue))
	/*
	 although we just used a sorted slice for a priority queue we could have used a heap
	 */
	
	for i:=0; i<numVert; i++{
		uStar:= pQueue[0]    // get the min dist item
		vertTree = append(vertTree, uStar.id) // put it in the tree
		pQueue = pQueue[1:]   // remove it from the queue
		for _,vertIdx := range uStar.nbr {
			u := vertList[vertIdx]  // convert the vertIdx to a vertex object
			if !(Contains(vertTree, vertIdx)){  // if the vertex is not in the tree
				if uStar.dist + adjMat[uStar.id][u.id] < u.dist{
					// update dist
					u.dist = uStar.dist + adjMat[uStar.id][u.id] 
					// update parent
					u.parent = uStar.id
				}
			}
		}
		// sort the vertices so that the min at 0
		sort.Sort(Vertices(pQueue))
	}
	// the distance of the destination node is in its dist field
	fmt.Println("The distance from node",source,"to node", dest, "is", vertList[dest].dist)
	
	// path from dest to source
	path :=  []int {dest}
	
	// while we are not at the souce
	for ; path[len(path)-1] != source; {
		// put the parent of the last item into the slice
		parent := vertList[path[len(path)-1]].parent
		path = append(path, parent)
	}
	// path is the reverse of the path slice
	fmt.Print("The path is: ")
	for i:=len(path) - 1; i > 0; i--{
		fmt.Print(path[i],"->")
	}
	fmt.Println(path[0])
	
}
