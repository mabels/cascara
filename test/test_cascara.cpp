
#include "../src/cascara.hpp"


using namespace cascara;

int main() {
  int itCount = 0;
  describe("cascara", [&itCount]() {
    describe("cascara test", [&itCount]() {
      it("it 1", [&itCount]() {
          ++itCount;
      });
      it("it 2", [&itCount]() {
          ++itCount;
      });
    });
    it("it was called twice", [&itCount]() {
        assert.equal(itCount, 2);
    });
  });
  return exit();
}
