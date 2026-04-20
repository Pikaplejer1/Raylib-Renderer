STAGE 1 — pixels & framebuffer ✅
1. ✅ Makefile + raylib setup
2. ✅ Window + game loop
3. ✅ Framebuffer (pixel buffer → texture → screen)
4. ✅ writePixel()
5. ✅ Gradient (spatial, two color params)

STAGE 2 — 2D drawing
6. ✅ Bresenham line algorithm
7. ✅ drawLine(x0,y0,x1,y1,color)
8.  [✅] Vec2 struct {int x, y}  -- refactor drawLine to take Vec2 points
9.  [✅] drawTriangleOutline(Vec2 a, Vec2 b, Vec2 c, Color col) -- just 3 lines
10. [ ✅] fillTriangle(Vec2 a, Vec2 b, Vec2 c, Color col)
        research: "barycentric coordinates triangle", "scanline triangle fill"
        pick one method, understand it before coding

STAGE 3 — math foundations
11. [ ] Vec3 struct {float x, y, z}
12. [ ] vec3 operations: add, subtract, dot product, cross product
13. [ ] Mat4 struct (4x4 float matrix)
14. [ ] mat4 multiply
15. [ ] translation matrix, scale matrix, rotation matrix
        research: "3Blue1Brown Essence of Linear Algebra", 
                  "model matrix view matrix projection matrix"

STAGE 4 — 3D wireframe
16. [ ] project Vec3 → Vec2 (perspective projection)
        research: "perspective projection matrix from scratch",
                  "homogeneous coordinates"
17. [ ] hardcode a cube (8 vertices, 12 edges)
18. [ ] draw cube as wireframe
19. [ ] rotate cube with rotation matrix each frame

STAGE 5 — rasterize 3D
20. [ ] fillTriangle on cube faces (flat color per face)
21. [ ] Z-buffer / depth buffer
        research: "z-buffer algorithm", "painter's algorithm"
22. [ ] backface culling
        research: "backface culling", "surface normal vector"
23. [ ] load and render a .obj file
        research: "OBJ file format spec"

STAGE 6 — lighting
24. [ ] flat shading (one color per triangle based on light angle)
25. [ ] Gouraud shading (interpolate color per vertex)
26. [ ] Phong shading
        research: "Phong reflection model",
                  "ambient diffuse specular lighting",
                  "normal interpolation"

REFERENCE: tinyrenderer by Dmitry Sokolov (GitHub) -- your bible