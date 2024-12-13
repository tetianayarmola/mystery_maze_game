#pragma once

namespace mz
{
	class Object
	{
	public:
		Object();
		virtual ~Object(); //virtual destructor

		void Destroy(); //cutomer modifiable
		bool IsPendingDestroy() const { return _mIsPendingDestroy; }

	private:
		bool _mIsPendingDestroy;
	};
}