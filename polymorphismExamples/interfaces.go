package main

import "fmt"

type Animal interface {
	speak() string
}

type Human interface{
	wereSpeak() string
}

type Beaver struct{
}

type Marmot struct{
}

func (b Beaver) speak() string {
	return "I eat wood!!"
}

func (b Beaver) wereSpeak() string {
	return "I'm changing into a beavARRRRRRR!"
}

func (m Marmot) speak() string {
	return "Obviously you are not a golfer!!"
}

func (m Marmot ) wereSpeak() string {
	return "There's a beverage here!"
}

func whatDidYouSay(a Animal){
	fmt.Println(a.speak())
}

func wereDidYouSay(h Human){
	fmt.Println(h.wereSpeak())
}

func main(){
	b := new (Beaver)
	m := new (Marmot)

	whatDidYouSay(b)
	whatDidYouSay(m)
	
	wereDidYouSay(b)
	wereDidYouSay(m)
}