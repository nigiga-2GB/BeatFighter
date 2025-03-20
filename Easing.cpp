#include "Easing.h"
#include "Math.h"

namespace Easing
{
	float EaseInSine(float t)
	{
		return 1 - Math::Cos((t * Math::PI) / 2);
	}

	float EaseOutSine(float t)
	{
		return Math::Sin((t * Math::PI) / 2);
	}

	float EaseInOutSine(float t)
	{
		return -(Math::Cos(Math::PI * t) - 1) / 2;
	}

	float EaseInQuad(float t)
	{
		return t * t;
	}

	float EaseOutQuad(float t)
	{
		return 1 - (1 - t) * (1 - t);
	}

	float EaseInOutQuad(float t)
	{
		return t < 0.5 ? 2 * t * t : 1 - Math::Pow(-2 * t + 2, 2) / 2;
	}

	float EaseInCubic(float t)
	{
		return t * t * t;
	}

	float EaseOutCubic(float t)
	{
		return 1 - Math::Pow(1 - t, 3);
	}

	float EaseInOutCubic(float t)
	{
		return t < 0.5 ? 4 * t * t * t : 1 - Math::Pow(-2 * t + 2, 3) / 2;
	}

	float EaseInQuart(float t)
	{
		return t * t * t * t;
	}

	float EaseOutQuart(float t)
	{
		return 1 - Math::Pow(1 - t, 4);
	}

	float EaseInOutQuart(float t)
	{
		return t < 0.5 ? 8 * t * t * t * t : 1 - Math::Pow(-2 * t + 2, 4) / 2;
	}

	float EaseInQuint(float t)
	{
		return t * t * t * t * t;
	}

	float EaseOutQuint(float t)
	{
		return 1 - Math::Pow(1 - t, 5);
	}

	float EaseInOutQuint(float t)
	{
		return t < 0.5 ? 16 * t * t * t * t * t : 1 - Math::Pow(-2 * t + 2, 5) / 2;
	}

	float EaseInExpo(float t)
	{
		return t == 0 ? 0 : Math::Pow(2, 10 * t - 10);
	}

	float EaseOutExpo(float t)
	{
		return t == 1 ? 1 : 1 - Math::Pow(2, -10 * t);
	}

	float EaseInOutExpo(float t)
	{
		return t == 0
			? 0
			: t == 1
			? 1
			: t < 0.5
			? Math::Pow(2, 20 * t - 10) / 2
			: (2 - Math::Pow(2, -20 * t + 10)) / 2;
	}

	float EaseInCirc(float t)
	{
		return 1 - Math::Sqrt(1 - Math::Pow(t, 2));
	}

	float EaseOutCirc(float t)
	{
		return Math::Sqrt(1 - Math::Pow(t - 1, 2));
	}

	float EaseInOutCirc(float t)
	{
		return t < 0.5
			? (1 - Math::Sqrt(1 - Math::Pow(2 * t, 2))) / 2
			: (Math::Sqrt(1 - Math::Pow(-2 * t + 2, 2)) + 1) / 2;
	}

	float EaseInBack(float t)
	{
		const float c1 = 1.70158;
		const float c3 = c1 + 1;

		return c3 * t * t * t - c1 * t * t;
	}

	float EaseOutBack(float t)
	{
		const float c1 = 1.70158;
		const float c3 = c1 + 1;

		return 1 + c3 * Math::Pow(t - 1, 3) + c1 * Math::Pow(t - 1, 2);
	}

	float EaseInOutBack(float t)
	{
		const float c1 = 1.70158;
		const float c2 = c1 * 1.525;

		return t < 0.5
			? (Math::Pow(2 * t, 2) * ((c2 + 1) * 2 * t - c2)) / 2
			: (Math::Pow(2 * t - 2, 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2;
	}

	float EaseInElastic(float t)
	{
		const float c4 = (2 * Math::PI) / 3;

		return t == 0
			? 0
			: t == 1
			? 1
			: -Math::Pow(2, 10 * t - 10) * Math::Sin((t * 10 - 10.75) * c4);
	}

	float EaseOutElastic(float t)
	{
		const float c4 = (2 * Math::PI) / 3;

		return t == 0
			? 0
			: t == 1
			? 1
			: Math::Pow(2, -10 * t) * Math::Sin((t * 10 - 0.75) * c4) + 1;
	}

	float EaseInOutElastic(float t)
	{
		const float c5 = (2 * Math::PI) / 4.5;

		return t == 0
			? 0
			: t == 1
			? 1
			: t < 0.5
			? -(Math::Pow(2, 20 * t - 10) * Math::Sin((20 * t - 11.125) * c5)) / 2
			: (Math::Pow(2, -20 * t + 10) * Math::Sin((20 * t - 11.125) * c5)) / 2 + 1;
	}

	float EaseInBounce(float t)
	{
		return 1 - EaseOutBounce(1 - t);
	}

	float EaseOutBounce(float t)
	{
		const float n1 = 7.5625;
		const float d1 = 2.75;

		if (t < 1 / d1) return n1 * t * t;
		else if (t < 2 / d1) return n1 * (t -= 1.5 / d1) * t + 0.75;
		else if (t < 2.5 / d1) return n1 * (t -= 2.25 / d1) * t + 0.9375;
		else return n1 * (t -= 2.625 / d1) * t + 0.984375;
	}

	float EaseInOutBounce(float t)
	{
		return t < 0.5
			? (1 - EaseOutBounce(1 - 2 * t)) / 2
			: (1 + EaseOutBounce(2 * t - 1)) / 2;
	}
}