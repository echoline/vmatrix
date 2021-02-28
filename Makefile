all:
	cd lib; make; cd ..; \
	cd src; make; cd ..

install: all
	cd src; make install; cd ..

clean:
	cd lib; make clean; cd ..; \
	cd src; make clean; cd ..

