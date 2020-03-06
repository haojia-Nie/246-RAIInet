RAIInet: textdisplay.o window.o graphicsdisplay.o ability.o board.o player.o cell.o link.o observer.o subject.o main.cc
	g++ -std=c++14 textdisplay.o window.o graphicsdisplay.o ability.o board.o player.o cell.o link.o observer.o subject.o main.cc -o RAIInet -lX11
graphicsdisplay.o: graphicsdisplay.cc
	g++ -std=c++14 graphicsdisplay.cc -c
ability.o: ability.cc
	g++ -std=c++14 ability.cc -c
board.o: board.cc
	g++ -std=c++14 board.cc -c
textdisplay.o: textdisplay.cc
	g++ -std=c++14 textdisplay.cc -c
player.o: player.cc
	g++ -std=c++14 player.cc -c
cell.o: cell.cc
	g++ -std=c++14 cell.cc -c
link.o: link.cc
	g++ -std=c++14 link.cc -c
window.o: window.cc
	g++ -std=c++14 window.cc -c
observer.o: observer.cc
	g++ -std=c++14 observer.cc -c
subject.o: subject.cc
	g++ -std=c++14 subject.cc -c
