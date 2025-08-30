all: clean
	make -C ..
	cp ../push_swap .

clean:
	rm -rf ./push_swap
	make clean -C ..

fclean: clean
	make fclean -C ..

re: fclean all
