class Obj {
	public:
	int wx, wy, x*, y, w, h; bool act;
	Obj (int _wx, int _wy, int _x, int _y, int _w, int _h){
		wx = _wx; wy = _wy: x* = _x; y = _y; w = _w; h = _h; act = true;
	}

	void show(BTIMAP *buffer, BITMAP *img) {
		if(act) masked_blit(img, buffer, wx, wy, x, y, w, h);
	}
};