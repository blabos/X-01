/*
 * stock.c
 *
 *  Created on: Sep 19, 2009
 *      Author: blabos
 */
#include "stock.h"

#include <stdlib.h>

stock_t*	_get_stock();
int			_random(int a, int b);
int			_request_item(int* item, int quant);


void stock_init() {
	stock_t* stock = _get_stock();
	
	stock->bean = 0;
	stock->corn = 0;
	stock->milk = 0;
	stock->rice = 0;
	stock->wine = 0;
	
	srand(time(NULL));
}

void stock_reload() {
	stock_t* stock = _get_stock();
	
	stock->bean += _random(MIN_STOCK_RELOAD, MAX_STOCK_RELOAD);
	stock->corn += _random(MIN_STOCK_RELOAD, MAX_STOCK_RELOAD);
	stock->milk += _random(MIN_STOCK_RELOAD, MAX_STOCK_RELOAD);
	stock->rice += _random(MIN_STOCK_RELOAD, MAX_STOCK_RELOAD);
	stock->wine += _random(MIN_STOCK_RELOAD, MAX_STOCK_RELOAD);
}

int stock_rice() { return _get_stock()->rice; }
int stock_bean() { return _get_stock()->bean; }
int stock_corn() { return _get_stock()->corn; }
int stock_milk() { return _get_stock()->milk; }
int stock_wine() { return _get_stock()->wine; }

int stock_request_rice(int quant) {
	return _request_item(&(_get_stock()->rice), quant);
}

int stock_request_bean(int quant) {
	return _request_item(&(_get_stock()->bean), quant);
}

int stock_request_corn(int quant)  {
	return _request_item(&(_get_stock()->corn), quant);
}

int stock_request_milk(int quant)  {
	return _request_item(&(_get_stock()->milk), quant);
}

int stock_request_wine(int quant)  {
	return _request_item(&(_get_stock()->wine), quant);
}


stock_t* _get_stock() {
	static stock_t _stock;
	
	return &_stock;
}

int _random(int a, int b) {
	return a + (rand() % abs(1 + b - a));
}

int _request_item(int* item, int quant) {
	quant = abs(quant);
	
	if (((*item) - quant) >= 0) {
		(*item) -= quant;
	}
	else {
		quant = -1;
	}
	
	return quant;
}
