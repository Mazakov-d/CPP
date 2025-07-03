#include "Point.hpp"
#include <iostream>

// BSP function prototype (usually in Point.hpp or separate header)
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl;
    
    // Define triangle vertices
    Point a(0.0f, 0.0f);     // Bottom-left
    Point b(4.0f, 0.0f);     // Bottom-right  
    Point c(2.0f, 3.0f);     // Top
    
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
    std::cout << std::endl;
    
    // Test cases
    struct TestCase {
        Point point;
        std::string description;
        bool expected;
    };
    
    TestCase tests[] = {
        // Points inside triangle
        {Point(2.0f, 1.0f), "Center of triangle", true},
        {Point(1.0f, 0.5f), "Inside near bottom-left", true},
        {Point(3.0f, 0.5f), "Inside near bottom-right", true},
        {Point(2.0f, 2.0f), "Inside near top", true},
        
        // Points outside triangle
        {Point(-1.0f, 0.0f), "Outside left", false},
        {Point(5.0f, 0.0f), "Outside right", false},
        {Point(2.0f, -1.0f), "Outside bottom", false},
        {Point(2.0f, 4.0f), "Outside top", false},
        {Point(0.0f, 2.0f), "Outside left side", false},
        {Point(4.0f, 2.0f), "Outside right side", false},
        
        // Edge cases - points on vertices (should be false)
        {Point(0.0f, 0.0f), "On vertex A", false},
        {Point(4.0f, 0.0f), "On vertex B", false},
        {Point(2.0f, 3.0f), "On vertex C", false},
        
        // Edge cases - points on edges (should be false)
        {Point(2.0f, 0.0f), "On edge AB", false},
        {Point(1.0f, 1.5f), "On edge AC", false},
        {Point(3.0f, 1.5f), "On edge BC", false},
        
        // Corner cases
        {Point(0.1f, 0.1f), "Just inside near A", true},
        {Point(3.9f, 0.1f), "Just inside near B", true},
        {Point(2.0f, 2.9f), "Just inside near C", true}
    };
    
    int testCount = sizeof(tests) / sizeof(TestCase);
    int passed = 0;
    
    for (int i = 0; i < testCount; i++) {
        bool result = bsp(a, b, c, tests[i].point);
        bool success = (result == tests[i].expected);
        
        std::cout << "Test " << (i + 1) << ": " << tests[i].description << std::endl;
        std::cout << "  Point: " << tests[i].point << std::endl;
        std::cout << "  Expected: " << (tests[i].expected ? "true" : "false") << std::endl;
        std::cout << "  Got: " << (result ? "true" : "false") << std::endl;
        std::cout << "  Result: " << (success ? "✓ PASS" : "✗ FAIL") << std::endl;
        std::cout << std::endl;
        
        if (success) passed++;
    }
    
    std::cout << "=== Summary ===" << std::endl;
    std::cout << "Passed: " << passed << "/" << testCount << " tests" << std::endl;
    
    if (passed == testCount) {
        std::cout << "🎉 All tests passed!" << std::endl;
    } else {
        std::cout << "❌ Some tests failed. Check your BSP implementation." << std::endl;
    }
    
    // Additional triangle test
    std::cout << std::endl << "=== Additional Triangle Test ===" << std::endl;
    Point a2(1.0f, 1.0f);
    Point b2(5.0f, 1.0f);
    Point c2(3.0f, 4.0f);
    Point test_point(3.0f, 2.0f);
    
    std::cout << "Triangle 2: A2" << a2 << ", B2" << b2 << ", C2" << c2 << std::endl;
    std::cout << "Test point: " << test_point << std::endl;
    std::cout << "Inside triangle: " << (bsp(a2, b2, c2, test_point) ? "Yes" : "No") << std::endl;
    
    return 0;
}