//////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////

struct aiScene;
struct aiNode;

#include "Car.h"

class MyApp : App
{
	void		OnInit() override;
	bool		OnUpdate() override;
	void		OnClose() override;
	void		InitPhysics();
	void		UpdatePhysics();
	void		DrawPhysics();
	void		CleanUpPhysics();
	void		UpdateCamera();
	void		Draw2DAxes(int x, int y, int w, int h);
	void		CountParameters();
	void		DrawParameters();
	void		Draw();
	void		DumpNode(aiScene const *scene, aiNode const *node, int indent = 0);
	void		DrawNode(aiScene const *scene, aiNode const *node);
	void		CreateRamp();
	void		DeleteRamp();

	uint									mFrame;
	Timer									mTimer;
	double									mElapsedTime;
	float									mDeltaTime;
	Camera									mCamera;

	enum EditMode : int
	{
		Edit = 0,
		Drive,
		NumModes
	};

	enum ControlMode
	{
		Idle = 0,
		Pan,
		Rotate
	};

	enum Axis
	{
		X = 0,
		Y = 1,
		Z = 2
	};

	struct ViewWindow
	{
		int				mLeft;
		int				mTop;
		int				mRight;
		int				mBottom;
		Axis			mAxis;
		Axis			mXAxis;
		Axis			mYAxis;
		Axis			mUpAxis;
		bool			mOrtho;		// else 3D (and draw the grid as well)
		Vec2			mPan;
		float			mTargetZoom;
		float			mZoom;
		float			mFlip;
		ControlMode		mControlMode;

		ViewWindow(int left, int top, int right, int bottom, Axis axis, Axis upAxis, Axis xAxis, Axis yAxis, bool ortho, float flip = 1.0f)
			: mLeft(left)
			, mTop(top)
			, mRight(right)
			, mBottom(bottom)
			, mAxis(axis)
			, mUpAxis(upAxis)
			, mXAxis(xAxis)
			, mYAxis(yAxis)
			, mOrtho(ortho)
			, mPan(0,0)
			, mTargetZoom(30)
			, mZoom(30)
			, mControlMode(Idle)
			, mFlip(flip)
		{
		}

		bool IsActive() const
		{
			return mControlMode != Idle;
		}
	};

	void DrawViewWindow(ViewWindow *w);

	int										mEditMargin;
	ViewWindow *							mViewWindow[4];
	ViewWindow *							mActiveViewWindow;

	Matrix									mCarOrientation;

	Vec3									mPosition;
	Vec3									mTarget;
	float									mYaw;
	float									mPitch;
	float									mRoll;

	Model *									mModel;

	Model *									mCylinder;
	Mesh *									mCylinderMesh;
	VertexBuffer *							mCylinderVB;
	IndexBuffer *							mCylinderIB;

	Console	*								mConsole;
	ImmediateContext *						mImmediateContext;
	SpriteList *							mSpriteList;
	VertexShader *							mVertexShader;
	PixelShader *							mPixelShader;
	Texture *								mTexture;
	Material *								mMaterial;
	VertexBuffer *							mVertexBuffer;
	IndexBuffer *							mIndexBuffer;
	ConstantBuffer *						mConstantBuffer;
	Mesh *									mMesh;

	Axes *									mAxes;

	VertexShader *							m2DUntexturedVS;
	PixelShader *							m2DUntexturedPS;
	Material *								mUntexturedMaterial;
	ImmediateContext *						m2DUntexturedIC;

	int										mTransformConstantBufferIndex;

	Font *									mDebugFont;
	Font *									mBannerFont;
	Font *									mFixedSysFont;

	PhysicsDebug *							mPhysicsDebug;

	float									mSteering;
	Vec3									mCameraPos;
	float									mCameraDistance;
	float									mCameraHeight;
	float									mCameraTargetHeight;

	Vec2									mOldMouseDelta;
	float									mCameraYaw;
	float									mCameraPitch;

	Car *									mCar;
	EditMode								mEditMode;

	int										mParameterIndex;
	float									mScrollBarPos;
	float									mScrollBarVelocity;
	int										mNumParameterLines;

	btDefaultCollisionConfiguration *		collisionConfiguration;
	btCollisionDispatcher *					dispatcher;
	btBroadphaseInterface *					overlappingPairCache;
	btSequentialImpulseConstraintSolver *	solver;
	btDiscreteDynamicsWorld *				dynamicsWorld;
	btCollisionShape *						groundShape;
	btRigidBody *							groundRigidBody;

	btCollisionShape *						mRampShape;
	btRigidBody *							mRamp;

	btAlignedObjectArray<btCollisionShape*>	collisionShapes;
};

//////////////////////////////////////////////////////////////////////

