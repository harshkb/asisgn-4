#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

                                                // To find orientation of ordered triplet (p, q, r).
                                                // The function returns following values
                                                // 0 --> p, q and r are colinear
                                                // 1 --> Clockwise
                                                // 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;                     // colinear
    return (val > 0)? 1: 2;                     // clock or counterclock wise
}

                                                // Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
                                                // There must be at least 3 points
    if (n < 3) return;

                                                // Initialize Result
    vector<Point> hull;

                                                // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

                                            // Start from leftmost point, keep moving counterclockwise
                                            // until reach the start point again.  This loop runs O(h)
                                            // times where h is number of points in result or output.
    int p = l, q;
    do
    {
       hull.push_back(points[p]);            // Add current point to result
         q = (p+1)%n;                       // Search for a point 'q' such that orientation(p, x,
                                            // q) is counterclockwise for all points 'x'. The idea
                                            // is to keep track of last visited most counterclock-
                                            // wise point in q. If any point 'i' is more counterclock-
                                            // wise than q, then update q.

        for (int i = 0; i < n; i++)
        {

           if (orientation(points[p], points[i], points[q]) == 2)    // If i is more counterclockwise than current q, then
                q = i;                                               // update q

        }
        p = q;                  // Now q is the most counterclockwise with respect to p
                                // Set p as q for next iteration, so that q is added to
                                // result 'hull'
    } while (p != l);  // While we don't come to first point

    for (int i = 0; i < hull.size(); i++)                      // Print Result
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}


int main()
{
    int total;
    cout<<"number of points "<<endl;
    cin>>total;
    cout<<"enter the points"<<endl;
    Point points[total];
    for(int i=0;i<total;i++)
    {
        cin>>points[i].x>>points[i].y;
    }
    convexHull(points, total);
    return 0;
}
