all: vim gvim mvim

vim: runvim.c
	gcc -o vim runvim.c

gvim: vim
	cp vim gvim

mvim: vim
	cp vim mvim

clean:
	rm -f vim gvim mvim

