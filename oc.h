using std::vector;

class Path {
private:
  vector<int> u;

public:
  Path() : u() {
    
  }

  Path(vector<int> u) {
    this->u = u;
  }

  vector<int> getPath() {
    return this->u;
  }
  
  void insert(Path &r) {
    u.insert(u.end(), r.u.begin(), r.u.end());
  }

  Path operator*(Path &r) {
    Path up(this->u);
    
    up.insert(r);
    
    return up;
  }
};

class Weight {
  private:

  public:
    Weight() {
      
    }
};